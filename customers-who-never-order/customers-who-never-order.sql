/* Write your PL/SQL query statement below */
SELECT name AS Customers
FROM Customers
WHERE id not in (SELECT customerId FROM Orders);