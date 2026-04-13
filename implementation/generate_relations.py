import os

OUTPUT_DIR = os.path.curdir


def s(cell: int, t: int) -> str:
    return f"S{cell}_{t}"


def r(reg: int, t: int) -> str:
    return f"R{reg}_{t}"


def z(t: int) -> str:
    return f"Z_{t}"


def generate_strumok512_relations(T: int = 11, include_output: bool = True, known_outputs: bool = True) -> str:
    lines = []
    lines.append(f"#strumok512 {T} clocks")
    lines.append("connection relations")

    for t in range(T):
        lines.append(f"{r(2, t + 1)}, {r(1, t)}")
        lines.append(f"{r(1, t + 1)}, {r(2, t)}, {s(13, t)}")

        for j in range(15):
            lines.append(f"{s(j, t + 1)}, {s(j + 1, t)}")

        lines.append(f"{s(15, t + 1)}, {s(0, t)}, {s(11, t)}, {s(13, t)}")

        if include_output:
            lines.append(f"{z(t)}, {s(15, t)}, {r(1, t)}, {r(2, t)}, {s(0, t)}")

    if known_outputs and include_output:
        lines.append("known")
        for t in range(T):
            lines.append(z(t))

    lines.append("end")
    return "\n".join(lines)


def save_relation_file(T: int = 11, include_output: bool = True, known_outputs: bool = True) -> str:
    content = generate_strumok512_relations(
        T=T,
        include_output=include_output,
        known_outputs=known_outputs,
    )
    filename = f"relationfile_strumok512_{T}clk_knownz.txt"
    path = os.path.join(OUTPUT_DIR, filename)

    with open(path, "w", encoding="utf-8") as f:
        f.write(content)

    return path


def main():
    path = save_relation_file(T=11, include_output=True, known_outputs=True)
    print(f"Saved: {path}")


if __name__ == "__main__":
    main()
