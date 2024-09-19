with first_half_and_july as (
    select * from FIRST_HALF
    union
    select * from JULY
)

select FLAVOR
from first_half_and_july
group by FLAVOR
order by sum(TOTAL_ORDER) desc
limit 3;