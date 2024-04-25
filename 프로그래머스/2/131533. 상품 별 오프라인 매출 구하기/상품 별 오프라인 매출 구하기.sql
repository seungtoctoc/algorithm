-- 코드를 입력하세요
SELECT p.PRODUCT_CODE, sum(p.PRICE * o.SALES_AMOUNT) SALES
from PRODUCT p right join OFFLINE_SALE o
on p.PRODUCT_ID = o.PRODUCT_ID
group by p.PRODUCT_CODE
order by SALES desc, p.PRODUCT_CODE