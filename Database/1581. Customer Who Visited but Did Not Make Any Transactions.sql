
--https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/?envType=study-plan-v2&envId=top-sql-50

-- or count(customer_id) both will work
Select v.customer_id, count(v.visit_id) as count_no_trans  
FROM Visits v
LEFT JOIN Transactions t
on v.visit_id = t.visit_id
Where transaction_id is null
group by customer_id
