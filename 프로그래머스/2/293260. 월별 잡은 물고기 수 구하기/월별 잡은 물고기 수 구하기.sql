-- 코드를 작성해주세요
 select count(*) FISH_COUNT, month(TIME) MONTH
 from FISH_INFO
 group by MONTH
 having FISH_COUNT > 0
 order by MONTH