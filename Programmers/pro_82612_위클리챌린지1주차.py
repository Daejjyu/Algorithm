def solution(price, money, count):
    priceGauss = price*(count*(1+count))/2
    return 0 if money >= priceGauss else priceGauss-money