-- Problem Link: https://leetcode.com/problems/product-sales-analysis-i/?envType=study-plan-v2&envId=top-sql-50

SELECT product_name, year, price
FROM Sales s
LEFT JOIN Product p 
on s.product_id = p.product_id
