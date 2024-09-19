select month(START_DATE) MONTH, CAR_ID, count(*) RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where month(START_DATE) between 8 and 10
    and CAR_ID in (
        select CAR_ID from CAR_RENTAL_COMPANY_RENTAL_HISTORY
        where month(START_DATE) between 8 and 10
        group by CAR_ID
        having count(*) >= 5
    )
group by MONTH, CAR_ID
having RECORDS > 0
order by MONTH, CAR_ID desc