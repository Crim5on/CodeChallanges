#!/usr/bin/python3
# source: https://www.codewars.com/kata/55e2adece53b4cdcb900006c/train/python



def race(v1: int, v2: int, g: int) -> list:

    if(v1 >= v2):
        return None

    # NOTE: This is crucial: Do not use floats!
    t_sec_total = (g*60*60) / (v2 - v1)

    t_h = int(t_sec_total / (60 * 60))
    t_min = int((t_sec_total % (60 *60)) / 60)
    t_sec = int(t_sec_total % 60)

    result = [t_h, t_min, t_sec]
    return result



if __name__ == "__main__":
    result = race(720, 850, 70)
    print(result)
