import csv

class SimpleReflexAQIAgent:

    def __init__(self, file_path):
        self.file_path = file_path

    # Sensor: Read environmental data for a specific date
    def read_sensors(self, target_date):
        with open(self.file_path, 'r') as file:
            reader = csv.DictReader(file)

            for row in reader:
                if row.get("Date") == target_date:
                    pollutants = {}

                    # Extract only numeric pollutant values
                    for key, value in row.items():
                        try:
                            pollutants[key] = float(value)
                        except:
                            continue  # Ignore City, Date, etc.

                    return pollutants

        return None  # If date not found

    # Rule-based AQI calculation (Simplified method)
    def calculate_aqi(self, pollutants):
        if not pollutants:
            return 0

        # AQI = Maximum pollutant concentration
        return int(max(pollutants.values()))

    # Actuator: Decide AQI category + Traffic restriction
    def act(self):
        date = input("Enter date (DD-MM-YYYY): ")
        total_cars = int(input("Enter total number of registered cars: "))

        data = self.read_sensors(date)

        if data is None:
            print("Date not found in dataset.")
            return

        aqi = self.calculate_aqi(data)

        print("\n--- AQI REPORT ---")
        print("Date:", date)
        print("Sensor Data:", data)
        print("Calculated AQI:", aqi)

        # AQI Category and Car Restriction Policy
        if aqi <= 50:
            category = "Good"
            percent_allowed = 100
        elif aqi <= 100:
            category = "Satisfactory"
            percent_allowed = 80
        elif aqi <= 200:
            category = "Moderate"
            percent_allowed = 60
        elif aqi <= 300:
            category = "Poor"
            percent_allowed = 40
        elif aqi <= 400:
            category = "Very Poor"
            percent_allowed = 20
        else:
            category = "Severe"
            percent_allowed = 10

        allowed_cars = int(total_cars * percent_allowed / 100)
        restricted_cars = total_cars - allowed_cars

        print("AQI Category:", category)
        print("Percentage of Cars Allowed:", percent_allowed, "%")
        print("Cars Allowed on Road:", allowed_cars)
        print("Cars Restricted:", restricted_cars)


# Main Execution
if __name__ == "__main__":
    agent = SimpleReflexAQIAgent("aqi_data.csv")
    agent.act()
