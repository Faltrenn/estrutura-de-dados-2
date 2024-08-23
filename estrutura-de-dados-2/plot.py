import matplotlib.pyplot as plt
from matplotlib.ticker import ScalarFormatter
import os
import sys


def get_case_by_arg(arg: str) -> str:
    if arg == "b":
        return "best"
    if arg == "e":
        return "expected"
    return "worst"

args = sys.argv[1:]

x_values = []
y_values = []

files = []
cases = []
start_cases = -1
if "-c" in args:
    start_cases = args.index("-c") + 1
    files = args[: start_cases]
    cases = args[start_cases:]
else:
    cases = ["b", "e", "w"]
    files = args

files_path = []
for file in files:
    for case in cases:
        file_path = f"graficos/{file}-{get_case_by_arg(case)}.txt"
        if os.path.isfile(file_path):
            files_path.append(file_path)

for i, file in enumerate(files_path):
    x_values = []
    y_values = []
    with open(file, 'r') as f:
        for line in f:
            x_values.append(int(line.split(" ")[0]))
            y_values.append(int(line.split(" ")[1]))
    plt.plot(x_values, y_values, label=file[9:-4])
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
