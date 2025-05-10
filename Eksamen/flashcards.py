import tkinter as tk
import pandas as pd

# Last inn CSV-fil
#df = pd.read_csv("TTT4145_UltraVanskelige_Flashcards.csv")
#df = pd.read_csv("TTT4145_Flashcards.csv")
df = pd.read_csv("TTT4145_40_Vanskelige_Teorisporsmal.csv")

class FlashcardApp:
    def __init__(self, root, data):
        self.root = root
        self.root.title("📡 TTT4145 Flashcards")
        self.root.configure(bg="#f0f4f8")
        self.data = data
        self.index = 0
        self.showing_answer = False

        # Hovedramme
        self.card_frame = tk.Frame(root, bg="white", bd=2, relief=tk.RIDGE)
        self.card_frame.pack(padx=40, pady=40, fill="both", expand=True)

        # Spørsmål / svar-tekst
        self.text = tk.Label(
            self.card_frame, text="", font=("Helvetica", 16),
            bg="white", wraplength=600, justify="left"
        )
        self.text.pack(padx=20, pady=30)

        # Knappene
        self.button_frame = tk.Frame(root, bg="#f0f4f8")
        self.button_frame.pack(pady=(0, 20))

        self.toggle_button = tk.Button(
            self.button_frame, text="🎯 Vis svar", font=("Helvetica", 12, "bold"),
            bg="#4a90e2", fg="white", padx=20, pady=10,
            command=self.toggle
        )
        self.toggle_button.grid(row=0, column=0, padx=10)

        self.next_button = tk.Button(
            self.button_frame, text="➡ Neste", font=("Helvetica", 12, "bold"),
            bg="#50e3c2", fg="black", padx=20, pady=10,
            command=self.next_card
        )
        self.next_button.grid(row=0, column=1, padx=10)

        self.update_display()

    def update_display(self):
        row = self.data.iloc[self.index]
        self.text.config(text=row["Spørsmål"])
        self.toggle_button.config(text="🎯 Vis svar")
        self.showing_answer = False

    def toggle(self):
        row = self.data.iloc[self.index]
        if self.showing_answer:
            self.text.config(text=row["Spørsmål"])
            self.toggle_button.config(text="🎯 Vis svar")
        else:
            self.text.config(text=row["Svar"])
            self.toggle_button.config(text="🔁 Tilbake til spørsmål")
        self.showing_answer = not self.showing_answer

    def next_card(self):
        self.index = (self.index + 1) % len(self.data)
        self.update_display()

# Kjør app
if __name__ == "__main__":
    root = tk.Tk()
    app = FlashcardApp(root, df)
    root.mainloop()

