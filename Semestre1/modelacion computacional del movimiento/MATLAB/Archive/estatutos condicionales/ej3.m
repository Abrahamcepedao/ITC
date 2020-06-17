%ejercicio 3
%Ana Sofía Fernandes Moheno
%A01637799

num1 = input("enter number");
num2 =input("enter number");
num3 =input("enter number");
if num1 > num2
    if num1 > num3
        if num2 > num3
            fprintf("%i, %i, %i", num3, num2, num1)
        else
            fprintf("%i, %i, %i", num2, num3, num1)
        end 
    else
        fprintf("%i, %i, %i", num2, num1, num3)
    end
else
    if num2 > num3
        if num3 > num1
            fprintf("%i, %i, %i", num1, num3, num2)
        else
            fprintf("%i, %i, %i", num3, num1, num2)
        end 
    else
        fprintf("%i, %i, %i", num1, num2, num3)
    end
end





    
            

       
     