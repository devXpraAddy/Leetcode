# Write your MySQL query statement below

SELECT
    case
        WHEN
            id = (select max(id) from Seat) and id%2 = 1
            THEN id
        WHEN
            id%2 = 1  # odd condition
            THEN id + 1
        ELSE
            id - 1
    end as id, student
from Seat
order by id 