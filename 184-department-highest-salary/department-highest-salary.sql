# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.salary as Salary
from Department d left join Employee e on d.id=e.departmentId
where (e.departmentId, e.salary) in 
(select departmentId, max(salary) from Employee group by departmentId)