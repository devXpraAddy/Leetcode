-- Problem Link: https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/?envType=study-plan-v2&envId=top-sql-50

select unique_id, name
FROM Employees e
LEFT JOIN EmployeeUNI u
on e.id = u.id

