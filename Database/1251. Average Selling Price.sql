-- https://leetcode.com/problems/average-selling-price/description/?envType=study-plan-v2&envId=top-sql-50

Select p.product_id, IFNULL(ROUND(SUM(p.price*u.units)/SUM(u.units)  , 2),0) as average_price
FROM Prices p
LEFT JOIN UnitsSold u
on p.product_id = u.product_id
AND u.purchase_date >= p.start_date
AND u.purchase_date <= p.end_date
GROUP BY p.product_id
