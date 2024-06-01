-- https://leetcode.com/problems/monthly-transactions-i/description/?envType=study-plan-v2&envId=top-sql-50

SELECT 
    DATE_FORMAT(trans_date, '%Y-%m') AS month,
    country,
    COUNT(id) as trans_count,
    SUM(state = 'approved') as approved_count,
    SUM(amount) as trans_total_amount,
    SUM(IF(state = 'approved', amount, 0)) as approved_total_amount
FROM Transactions
GROUP BY month, country 
