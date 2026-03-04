This project focuses on designing a Simple Reflex Agent that takes environmental parameters from sensors (provided as a dataset file) and calculates the Air Quality Index (AQI). The dataset used in this project is based on historical air quality data from the year 2015. Therefore, all AQI calculations are performed using 2015 data only. Any selected date must belong to 2015, as the project does not use real-time or current environmental data.

The agent operates as a Simple Reflex Agent. This means it does not store past states or learn from previous data. Instead, it reacts only to the current environmental input provided from the dataset. The agent follows predefined AQI threshold rules to determine the air quality category. Its decision-making process is purely condition-based and does not involve memory or prediction.

The agent processes the following environmental parameters: NO, NO₂, NOx, CO, SO₂, O₃, Benzene, Toluene, and Xylene. For a selected date in 2015, the system reads the pollutant concentrations from the dataset and identifies the maximum pollutant concentration among them. This maximum value is then mapped to the AQI scale using predefined threshold ranges. Based on these ranges, the AQI is classified into one of the standard categories: Good, Satisfactory, Moderate, Poor, Very Poor, or Severe.

The step-by-step working of the system is as follows: first, pollutant concentration values are read from the dataset for a selected date in 2015. Next, the highest pollutant value is identified. That value is then compared against predefined AQI threshold ranges to determine the AQI score. Finally, the AQI score is categorized into the appropriate air quality classification.

As an extension to the basic AQI calculation, the system also includes traffic regulation logic based on the AQI level. Depending on the AQI category, the system can estimate whether vehicle restrictions are required, determine the approximate number of vehicles allowed on the road.

This project demonstrates the practical implementation of a rule-based AI agent using historical environmental data while also showcasing how AQI-based decisions can support environmental management and traffic control strategies.

