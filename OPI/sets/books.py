
M = int(input())
N = int(input())


library_books = set()
for _ in range(M):
    book = input().strip()
    library_books.add(book)

for _ in range(N):
    summer_book = input().strip()
    if summer_book in library_books:
        print("YES")
    else:
        print("NO")
