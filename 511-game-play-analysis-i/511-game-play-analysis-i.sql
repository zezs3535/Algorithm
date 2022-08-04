/* Write your PL/SQL query statement below */
select player_id, to_char(min(event_date)) first_login
from Activity
group by player_id;