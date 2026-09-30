# Write your MySQL query statement below
 
/* Write your T-SQL query statement below */

SELECT S.name 
FROM SalesPerson S
WHERE NOT EXISTS (
    SELECT 1
    FROM Orders O
    JOIN Company C
        ON O.com_id = C.com_id
    WHERE O.sales_id = S.sales_id
      AND C.name = 'RED'
);

   