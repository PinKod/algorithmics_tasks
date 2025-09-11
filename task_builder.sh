#!/bin/bash


read -p "Enter new task name (e.g., task_G): " new_task_name


if [[ ! "$new_task_name" =~ ^task_[A-Z]$ ]]; then
    echo "Error: Task name must be in format 'task_X' where X is a capital letter"
    exit 1
fi


task_letter=$(echo "$new_task_name" | cut -d'_' -f2)

if [ -d "tasks/$new_task_name" ]; then
    echo "Error: Task directory $new_task_name already exists"
    exit 1
fi


template_task="task_B"
echo "Using $template_task as template"


cp -r "tasks/$template_task" "tasks/$new_task_name"


if [ -f "tasks/$new_task_name/task.png" ]; then
    rm "tasks/$new_task_name/task.png"
fi


> "tasks/$new_task_name/c_src_1/solution.c"


sed -i "s/project($template_task)/project($new_task_name)/" "tasks/$new_task_name/CMakeLists.txt"


source_cmake="tasks/$new_task_name/c_src_1/CMakeLists.txt"
sed -i -E \
    -e "s/project\\(${template_task}_1[^)]*\\)/project(${new_task_name}_1)/" \
    -e "s/${template_task}_solution_1/${new_task_name}_solution_1/g" \
    "$source_cmake"



tasks_cmake="tasks/CMakeLists.txt"
if ! grep -q "add_subdirectory($new_task_name)" "$tasks_cmake"; then
    echo ' ' >> "$tasks_cmake"
    echo "add_subdirectory($new_task_name)" >> "$tasks_cmake"
fi