# Write your MySQL query statement below
select q1.person_name
-- Usi row ka person_name final answer hai.
from Queue q1 join Queue q2 on q1.turn>=q2.turn
-- har person ke liye usse pehle (aur us person ko include karke) sab log mil jaate hain.
group by q1.turn
-- Ek group = “current person tak ke sab log”
having sum(q2.weight)<=1000
-- Sirf un groups ko rakho jahan cumulative weight ≤ 1000.
order by sum(q2.weight) desc
-- Sabse bada cumulative (lekin ≤ 1000) upar aa jayega
limit 1
-- Bas top 1 row lo.
-- last person to fit in bus




-- Self-join + sum = prefix sum ban jata hai har turn tak.
-- Phir largest prefix ≤ 1000 choose karke last allowed person mil jata hai.