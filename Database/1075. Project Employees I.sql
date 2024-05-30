-- https://leetcode.com/problems/project-employees-i/description/?envType=study-plan-v2&envId=top-sql-50

Select p.project_id, ROUND(SUM(e.experience_years)/count(*),2) as average_years
FROM Project p
LEFT JOIN Employee e
on p.employee_id = e.employee_id
Group by p.project_id

#or

Select p.project_id, ROUND(AVG(e.experience_years),2) as average_years
FROM Project p
LEFT JOIN Employee e
on p.employee_id = e.employee_id
Group by p.project_id
