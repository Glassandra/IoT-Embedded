workers = {
    "Projekt A": {"Erik": 25, "Lina": 30, "Tomas": 20},
    "Projekt B": {"Lina": 35, "Erik": 40},
    "Projekt C": {"Tomas": 45, "Erik": 50}
}

hours_eric = ["",0]
lina_projects = {}

for project, worker_info in workers.items():
    for worker, hours in worker_info.items():
        if worker == "Erik" and hours > hours_eric[1]:
            hours_eric = [project, hours]
        if worker == "Lina" and hours > 30:
            lina_projects[project] = hours

print(f"Erik worked most on {hours_eric[0]} with {hours_eric[1]} hours.")
print("Linas projects with over 30 hours: " + str(lina_projects))
