with bought_milk as (
    select *
    from CART_PRODUCTS
    where NAME = 'Milk'
),
bought_yogurt as (
    select *
    from CART_PRODUCTS
    where NAME = 'Yogurt'
)

select distinct CART_ID
from CART_PRODUCTS
where CART_ID in (select CART_ID from bought_milk)
      and CART_ID in (select CART_ID from bought_yogurt)
order by CART_ID
