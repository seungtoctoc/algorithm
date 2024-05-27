-- 코드를 입력하세요
select a.AUTHOR_ID, a.AUTHOR_NAME, b.CATEGORY, SUM(bs.SALES * b.PRICE) TOTAL_SALES
from 
    BOOK_SALES bs 
    join BOOK b on bs.BOOK_ID = b.BOOK_ID
    join AUTHOR a on b.AUTHOR_ID = a.AUTHOR_ID
where DATE_FORMAT(bs.SALES_DATE, '%Y%m') = '202201'
group by b.AUTHOR_ID, b.CATEGORY
order by b.AUTHOR_ID, b.CATEGORY desc
