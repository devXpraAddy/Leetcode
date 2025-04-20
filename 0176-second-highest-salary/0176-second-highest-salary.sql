# Write your MySQL query statement below

Select MAX(salary) as SecondHighestSalary
from Employee 
where salary < (
    select MAX(salary)
    from Employee
)