Select author_id as id
FROM Views
WHERE author_id = viewer_id
group by id
order by id asc