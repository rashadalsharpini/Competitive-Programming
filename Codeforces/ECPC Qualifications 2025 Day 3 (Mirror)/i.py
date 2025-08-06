h, m = map(int, input().split(':'))
print(f"{((h + 5) % 24):02d}:{m:02d}")
