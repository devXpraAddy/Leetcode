-- https://leetcode.com/problems/find-customer-referee/?envType=study-plan-v2&envId=top-sql-50

select name
FROM Customer
WHERE referee_id is null or referee_id != 2