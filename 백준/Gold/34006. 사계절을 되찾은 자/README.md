# [Gold I] 사계절을 되찾은 자 - 34006 

[문제 링크](https://www.acmicpc.net/problem/34006) 

### 성능 요약

메모리: 43380 KB, 시간: 356 ms

### 분류

그래프 이론, 그래프 탐색, 너비 우선 탐색, 역추적

### 제출 일자

2025년 5월 28일 03:55:22

### 문제 설명

<div class="center-image"><img alt="카링 사진" src="https://upload.acmicpc.net/27430192-03af-4eff-a5e9-d179a4fdafb0/-"></div>

<p><span class="kaling-text">카링</span>은 2023년 2월 23일에 추가된 메이플스토리 최상위 보스 몬스터로, <span class="kaling-text">카링</span>과 대결하는 동안 계절의 균형을 유지해야 하는 독특한 게이지 시스템을 가지고 있다.</p>

<div class="center-image"><img alt="균형된 게이지 사진" src="https://upload.acmicpc.net/3cbda185-166a-4a06-b4b6-bdc447029922/-"></div>

<p style="text-align: center;">계절의 균형: 게이지 시스템</p>

<p>노란색 게이지를 <span class="spring-text">봄의 기운</span>, 파란색 게이지를 <span class="summer-text">여름의 기운</span>, 보라색 게이지를 <span class="fall-text">가을의 기운</span>이라고 한다. 각 게이지의 양은 $0$ 이상 $2N$ 이하의 정수로 표현할 수 있다. 각 게이지의 양을 합치면 항상 $3N$이며 게이지 총량은 항상 변하지 않는다고 가정한다. 처음에는 <span class="spring-text">봄의 기운</span>은 <span style="color:#f2ce39;"><strong>$A$</strong></span>, <span class="summer-text">여름의 기운</span>은 <strong><span style="color:#0188f2;">$B$</span></strong>, <span class="fall-text">가을의 기운</span>은 <span style="color:#b361c5;"><strong>$C$</strong></span>만큼 있다.</p>

<p><span class="kaling-text">카링</span>이 공격하는 종류에 따라 피격 당했을 때, 게이지 변화가 다르다. 게이지 변화는 다음 $3$가지 중 하나에 해당한다.</p>

<ul>
	<li><span class="spring-text">궁기의 공격</span>: <span class="spring-text">봄의 기운</span>이 <span style="color:#f2ce39;"><strong>$a$</strong></span>만큼 상승한다. 동시에 <span class="fall-text">가을의 기운</span>이 <span style="color:#f2ce39;"><strong>$a$</strong></span>만큼 감소한다.</li>
	<li><span class="summer-text">도올의 공격</span>: <span class="summer-text">여름의 기운</span>이 <strong><span style="color:#0188f2;">$b$</span></strong>만큼 상승한다. 동시에 <span class="spring-text">봄의 기운</span>이 <strong><span style="color:#0188f2;">$b$</span></strong>만큼 감소한다.</li>
	<li><span class="fall-text">혼돈의 공격</span>: <span class="fall-text">가을의 기운</span>이 <span style="color:#b361c5;"><strong>$c$</strong></span>만큼 상승한다. 동시에 <span class="summer-text">여름의 기운</span>이 <span style="color:#b361c5;"><strong>$c$</strong></span>만큼 감소한다.</li>
</ul>

<p>계절의 균형을 이루려면 한 게이지라도 $0$ 이하가 되거나, $2N$ 이상이 되지 않아야 한다.</p>

<div class="center-image"><img alt="균형이 깨진 게이지 사진" src="https://upload.acmicpc.net/4316ea4d-884e-4bfb-96bf-42e07da9ed22/-"></div>

<p style="text-align: center;">$N=500$일 때, <span class="spring-text">봄의 기운</span>이 <span style="color:#f2ce39;"><strong>$1\,000$</strong></span>, <span class="fall-text">가을의 기운</span>이 <span style="color:#b361c5;"><strong>$0$</strong></span>이 되어 균형이 깨진 상태</p>

<p>따라서 계절의 균형을 안전하게 유지하기 위해 각 게이지의 양을 $N$에 가깝게 유지하는 것이 중요하다. 계절의 균형을 맞추는 방법을 터득해 <span class="kaling-text">카링</span> 게이지 시스템을 파훼 해보자! 처음 상태의 게이지가 주어졌을 때, 모두 $N$으로 맞추기 위한 최소 피격 횟수를 구하고, 그 공격을 어떤 순서로 피격 당해야 하는지 구해보자.</p>

### 입력 

 <p>첫 번째 줄에 $N$이 주어진다. $(2 \le N \le 1\,000)$</p>

<p>두 번째 줄에 정수 <span style="color:#f2ce39;"><strong>$A$</strong></span>, <strong><span style="color:#0188f2;">$B$</span></strong>, <span style="color:#b361c5;"><strong>$C$</strong></span>가 공백으로 구분되어 주어진다. $(0 \lt $<span style="color:#f2ce39;"><strong>$A$</strong></span>$, $<strong><span style="color:#0188f2;">$B$</span></strong>$, $<span style="color:#b361c5;"><strong>$C$</strong></span>$ \lt 2N$; <span style="color:#f2ce39;"><strong>$A$</strong></span>$+$<strong><span style="color:#0188f2;">$B$</span></strong>$+$<span style="color:#b361c5;"><strong>$C$</strong></span>$=3N)$</p>

<p>세 번째 줄에 정수 <span style="color:#f2ce39;"><strong>$a$</strong></span>, <strong><span style="color:#0188f2;">$b$</span></strong>, <span style="color:#b361c5;"><strong>$c$</strong></span>가 공백으로 구분되어 주어진다. $(0 \lt $<span style="color:#f2ce39;"><strong>$a$</strong></span>$, $<strong><span style="color:#0188f2;">$b$</span></strong>$, $<span style="color:#b361c5;"><strong>$c$</strong></span>$ \lt 2N)$</p>

<p>처음부터 각 게이지의 양이 모두 $N$인 경우는 주어지지 않는다.</p>

### 출력 

 <p>만약 계절의 균형을 안전하게 유지하면서 게이지를 모두 $N$으로 맞추는 것이 가능하다면</p>

<ul>
	<li>첫 번째 줄에 최소 피격 횟수를 $M$을 출력한다.</li>
	<li>두 번째 줄에 길이가 $M$인 문자열 $S$를 출력한다. 문자열 $S$의 $i$번째 문자는 $i$번째로 어떤 종류의 공격을 피격 당했는지를 의미한다. $(1 \le i \le M)$
	<ul>
		<li>만약 문자가 <code><span class="spring-text">A</span></code>라면 <span class="spring-text">궁기의 공격</span>을, <code><span class="summer-text">B</span></code>라면 <span class="summer-text">도올의 공격</span>을, <code><span class="fall-text">C</span></code>라면 <span class="fall-text">혼돈의 공격</span>을 피격 당했다는 의미이다.</li>
	</ul>
	</li>
	<li>만약 가능한 문자열 $S$가 여러 가지라면 사전 순으로 가장 앞서는 문자열 $S$를 출력한다.</li>
</ul>

<p>만약 계절의 균형을 안전하게 유지하면서 게이지를 모두 $N$으로 맞추는 것이 불가능하다면</p>

<ul>
	<li>첫 번째 줄에 <code><span class="kaling-text">-1</span></code>을 출력한다.</li>
</ul>

