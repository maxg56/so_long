

file_mlx42_int_path = "./include/MLX42_Int.h"
file_mlx42_path = "./include/MLX42.h"

# Define function to extract comments
def extract_comments(file_path):
    comments = []
    with open(file_path, 'r') as file:
        for line in file:
            line = line.strip()
            # Extract single-line and multi-line comments
            if line.startswith("//") or line.startswith("/*") or line.startswith("*"):
                comments.append(line)
    return comments

# Extract comments from both files
comments_int = extract_comments(file_mlx42_int_path)
comments_mlx42 = extract_comments(file_mlx42_path)

# Combine and format comments for Markdown
markdown_content = "### Extracted Comments from MLX42_Int.h\n\n"
markdown_content += "\n".join(comments_int) + "\n\n"
markdown_content += "### Extracted Comments from MLX42.h\n\n"
markdown_content += "\n".join(comments_mlx42) + "\n"

# Return the markdown content
print(markdown_content)
