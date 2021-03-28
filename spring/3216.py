def min_waiting_time(n, m_length, d_length):
	time_needed = [0 for _ in range(n)]
	time_needed[0] = d_length[0]
	m_sum = m_length[0]
	d_sum = d_length[0]
	for i in range(1, n):
		time_needed[i] = max(d_length[i] + d_sum - m_sum, time_needed[i-1])
		m_sum += m_length[i]
		d_sum += d_length[i]
	return time_needed[-1]


n = int(input())

m_length = []
d_length = []

for i in range(n):
    tmp = input().split()
    m_length.append(int(tmp[0]))
    d_length.append(int(tmp[1]))

print(min_waiting_time(n, m_length, d_length))