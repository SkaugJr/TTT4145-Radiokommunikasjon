with open("datapakker10bytesCounter", "w") as f:
    for i in range(1_000):
        f.write(f"Pakke{i:03d}\n")