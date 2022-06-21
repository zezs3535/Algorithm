/* Write your PL/SQL query statement below */
select a.customer_id, count(*) count_no_trans
from Visits a
where a.visit_id not in (
    select distinct visit_id from Transactions
)
group by a.customer_id;
