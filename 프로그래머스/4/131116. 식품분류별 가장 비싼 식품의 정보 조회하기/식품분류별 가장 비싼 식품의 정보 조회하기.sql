-- 코드를 입력하세요

select o.CATEGORY, m.MAX_PRICE, o.PRODUCT_NAME
from FOOD_PRODUCT o right join (
    select CATEGORY, MAX(PRICE) MAX_PRICE
    from FOOD_PRODUCT
    group by CATEGORY
) m
on m.CATEGORY = o.CATEGORY and m.MAX_PRICE = o.PRICE
where o.CATEGORY IN ('과자', '국', '김치', '식용유')
order by m.MAX_PRICE desc
