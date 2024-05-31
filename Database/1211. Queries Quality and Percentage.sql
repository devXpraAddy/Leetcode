-- https://leetcode.com/problems/queries-quality-and-percentage/description/?envType=study-plan-v2&envId=top-sql-50

Select query_name, ROUND(AVG(rating/position),2) as quality, ROUND(COUNT(CASE WHEN rating<3 THEN 1 END)*100/COUNT(rating),2) as poor_query_percentage
FROM Queries
WHERE query_name is not null
GROUP BY query_name
