-- 코드를 입력하세요
SELECT ANIMAL_TYPE, count(*) as count
from ANIMAL_INS
group by ANIMAL_TYPE
having ANIMAL_TYPE = 'Cat' OR ANIMAL_TYPE = 'Dog'
order by ANIMAL_TYPE;