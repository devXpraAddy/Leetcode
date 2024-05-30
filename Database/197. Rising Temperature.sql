-- https://leetcode.com/problems/rising-temperature/description/?envType=study-plan-v2&envId=top-sql-50


Select w2.id
FROM Weather w1
INNER JOIN Weather w2
WHERE Datediff(w2.recordDate, w1.recordDate) = 1
and w2.temperature > w1.temperature
