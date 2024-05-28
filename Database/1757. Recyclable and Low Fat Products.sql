--https://leetcode.com/problems/recyclable-and-low-fat-products/?envType=study-plan-v2&envId=top-sql-50

select product_id from Products 
WHERE low_fats = 'Y' and recyclable = 'Y'