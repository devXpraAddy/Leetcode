-- https://leetcode.com/problems/average-time-of-process-per-machine/description/?envType=study-plan-v2&envId=top-sql-50


select a1.machine_id, ROUND(avg(a2.timestamp - a1.timestamp),3) as processing_time
FROM Activity a1
INNER JOIN Activity a2
on a1.machine_id = a2.machine_id
AND a1.process_id = a2.process_id
AND a1.timestamp<a2.timestamp
group by machine_id
