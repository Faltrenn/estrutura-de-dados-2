import matplotlib.pyplot as plt
from matplotlib.ticker import ScalarFormatter
import os
import sys


def get_case_by_arg(arg: str) -> str:
    if arg == "b":
        return "best"
    if arg == "m":
        return "medium"
    return "worst"

args = sys.argv[1:]

x_values = []
y_values = []

file = []
cases = []
start_cases = -1
if "-c" in args:
    start_cases = args.index("-c") + 1
    files = args[: start_cases]
    cases = args[start_cases:]
else:
    cases = ["b", "m", "w"]
    files = args

files_path = []
for file in files:
    for case in cases:
        file_path = f"tests/{file}-{get_case_by_arg(case)}.txt"
        if os.path.isfile(file_path):
            files_path.append(file_path)

x_values = list(range(1, 101))
for i, file in enumerate(files_path):
    y_values.append([])
    with open(file, 'r') as f:
        for line in f:
            y_values[i].append(int(line))
    plt.plot(x_values, y_values[i], label=file[6:-4])
plt.xlabel('Tamanho')
plt.ylabel('Tempo(ns)')
plt.title('Gráfico de Linha')
plt.legend()
plt.grid(True)

plt.gca().yaxis.set_major_formatter(ScalarFormatter(useOffset=False))
plt.ticklabel_format(style='plain', axis='y')

plt.ylim(bottom=0)
plt.xlim(left=0, right=x_values[-1])

plt.tight_layout()

#plt.savefig('grafico.png')
plt.show()
