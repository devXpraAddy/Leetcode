# Write your MySQL query statement below

Select email as Email
FROM Person
group by email
Having count(email) >=2
