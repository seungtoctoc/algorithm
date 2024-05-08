-- 코드를 작성해주세요
select year(YM) YEAR, round(avg(PM_VAL1),2) PM10, round(avg(PM_VAL2), 2) 'PM2.5'
from AIR_POLLUTION
where LOCATION2 = '수원'
group by year(YM)
order by year(YM)