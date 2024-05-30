-- https://leetcode.com/problems/not-boring-movies/description/?envType=study-plan-v2&envId=top-sql-50


Select id, movie, description, rating
FROM Cinema
WHERE id%2 !=0 and description != "boring"
ORDER BY rating desc
