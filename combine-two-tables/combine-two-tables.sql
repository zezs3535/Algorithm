/* Write your PL/SQL query statement below */
SELECT a.firstName AS FIRSTNAME, a.lastName as LASTNAME, b.city as CITY, b.state as STATE
FROM Person a, Address b
WHERE a.personId = b.personId(+);