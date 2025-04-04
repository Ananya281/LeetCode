# Write your MySQL query statement below

select round(count(distinct player_id)/(select count(distinct player_id) from Activity),2) as fraction
from Activity where
(player_id,date_sub(event_date,interval 1 day)) in (select player_id,min(event_date) from Activity group by player_id)

-- DATE_ADD and DATE_SUB are used to add or subtract time from a date in MySQL.

-- \U0001f4cc Difference:
-- DATE_ADD(date, INTERVAL value unit) → Adds time to a date.

-- DATE_SUB(date, INTERVAL value unit) → Subtracts time from a date.