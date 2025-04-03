# Write your MySQL query statement below
-- select sum(confirmed_entries)/count(*)
-- from (select count(*) as confirmed_entries from Confirmations group by user_id having action='confirmed') as Confirm4

-- select user_id,if(sum(confirmed_entries)/count(*),1,0) as confirmation_rate 
-- from (select user_id)


select s.user_id,ifnull(round(sum(action='confirmed')/count(*),2),0.00) as confirmation_rate
from Signups s left join Confirmations c on s.user_id=c.user_id
group by s.user_id