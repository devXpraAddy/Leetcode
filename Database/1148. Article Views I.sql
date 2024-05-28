--https://leetcode.com/problems/article-views-i/description/?envType=study-plan-v2&envId=top-sql-50

Select author_id as id
FROM Views
WHERE author_id = viewer_id
group by id
order by id asc
