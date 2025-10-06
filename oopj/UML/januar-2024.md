<img width="1141" height="276" alt="image" src="https://github.com/user-attachments/assets/c8b5f76e-29bb-48ad-a201-ac0f0217ac9d" />

```mermaid

classDiagram
    class Program {
        +process(document: Document): void
    }
    class Document {
        -title: string
        -created_date: Date
        -last_save_date: Date
        -location: string
        -author: string
        +save_to_external_service(location: string): void
    }
    class Paragraph {
        -text: string
        -image: Image
    }
    class Image {
        -path: string
    }
    class Sentence {
        -content: string
    }
    class Token {
        -type: string (char_sequence, number, space, punctuation)
        -value: string
    }
    Program --> Document: processes
    Document *-- Paragraph: contains
    Paragraph *-- Sentence: contains
    Sentence *-- Token: contains
    Paragraph --> Image: optional
    Document --> DropBox: saves to
    Document --> OneDrive: saves to

```
