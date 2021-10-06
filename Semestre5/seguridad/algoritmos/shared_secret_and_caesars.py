def calculate_shared_secret(Xa, Yb, g, p):
    import math
    c = math.pow(Yb, Xa)
    d = c % p
    return int(d)

def eval_shared_secret(Xa, Xb, g, p):
    import math
    c = math.pow(g, Xa * Xb)
    d = c % p
    return int(d)

def calculate_public(Xa, g, p):
    import math
    c = math.pow(g, Xa)
    Ya = int(c % p)
    print("Ya = ",Ya)

def get_private(p):
    Xa = None
    while not isinstance(Xa, int):
        try:
            Xa = int(input("Xa (between 1-{}): ".format(p-1)))
        except:
            continue
    return Xa

def get_public(p):
    Yb = None
    while not isinstance(Yb, int):
        try:
            Yb = int(input("Yb (between 1-{}): ".format(p-1)))
        except:
            continue
    return Yb

def verify_prime(n):
    from math import sqrt
    prime_flag = 0
    if(n > 1):
        for i in range(2, int(sqrt(n)) + 1):
            if (n % i == 0):
                prime_flag = 1
                break
        if (prime_flag == 0):
            return True
        return False
    else:
        return False


if __name__ == '__main__':
    """is_prime = False
    while is_prime is False:
        try:
            p = int(input("p (prime number <= 23): "))
            is_prime = verify_prime(p)
        except:
            continue"""
    g = 3
    p = 23
    print("p,g", p, g)

    ok = False
    while ok is False:
        Xa = get_private(p)
        calculate_public(Xa, g, p)
        Yb = get_public(p)
        shared = calculate_shared_secret(Xa, Yb, g, p)
        print("-" * 40)
        print("shared: {}".format(shared))
        print("-" * 40)

        print("Alice (Xa={})".format(Xa))
        Xb_poss = []
        for i in range(1,p):
            rx = eval_shared_secret(Xa, i, g, p)
            if rx == shared:
                Xb_poss.append(i)
        print("Xb_poss", Xb_poss)

        if len(Xb_poss) == 1:
            break
        else:
            print("Multiple solutions, trying again...\n")

print("=" * 80)
print("Xa ({}) has discovered Xb: {}".format(Xa,Xb_poss[0]))
Xb =  Xb_poss[0]
