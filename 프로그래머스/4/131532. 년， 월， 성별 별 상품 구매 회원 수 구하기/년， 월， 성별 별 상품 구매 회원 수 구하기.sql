-- 코드를 입력하세요

select OS.YEAR, OS.MONTH, UI.GENDER, count(distinct UI.USER_ID) USERS
from
(
    select USER_ID, year(SALES_DATE) YEAR, month(SALES_DATE) MONTH
    from ONLINE_SALE
) OS join USER_INFO UI
on OS.USER_ID = UI.USER_ID
group by OS.YEAR, OS.MONTH, UI.GENDER
having UI.GENDER is not null
order by YEAR, MONTH, GENDER