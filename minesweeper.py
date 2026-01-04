"""minesweeper.py

Small helper module for Minesweeper automation. Provides a simple
deterministic solver that uses two basic Minesweeper rules and can
optionally perform clicks via pyautogui. The module is safe to import
even when pyautogui is not installed; functions that require live
interaction will raise if pyautogui is missing.
"""

try:
	import pyautogui
except Exception:
	pyautogui = None

			"""

			try:
				import pyautogui
			except Exception as e:
				pyautogui = None
				print(
					"""minesweeper.py - deterministic Minesweeper solver + automation

					Uses simple deterministic rules to solve Minesweeper-like boards visible on screen.
					Run interactively; the script will not click unless you explicitly confirm.
					"""

					try:
						import pyautogui
					except Exception as e:
						pyautogui = None
						print(
							"Warning: pyautogui could not be imported.\n"
							"Install it with: python -m pip install pyautogui\n"
							"Error:",
							e,
						)


					def require_pyautogui():
						if pyautogui is None:
							raise RuntimeError("pyautogui is required. Install it with: python -m pip install pyautogui")
						return pyautogui


					def find_board_and_ui_defaults(screen_width=None, screen_height=None):
						"""Return default board rect and UI element coordinates for a typical 2k main monitor.

						Returns (board_left, board_top, board_width, board_height, flags_center, smiley_center)
						"""
						if screen_width is None or screen_height is None:
							screen_width, screen_height = pyautogui.size() if pyautogui else (2560, 1440)

						board_w = int(screen_width * 0.6)
						board_h = int(screen_height * 0.6)
						board_left = int((screen_width - board_w) / 2)
						board_top = int(screen_height * 0.18)

						flags_center = (board_left + int(board_w * 0.08), int(screen_height * 0.08))
						smiley_center = (board_left + int(board_w / 2), int(screen_height * 0.08))

						return (board_left, board_top, board_w, board_h, flags_center, smiley_center)


					def _classify_pixel(px):
						"""Return a simple classification for a sampled pixel.

						Possible returns: 'flag_color', 'blue', 'green', 'red', 'covered_gray', 'empty_light', 'other'
						"""
						r, g, b = px[:3]
						# Flag pixels (bright red)
						if r > 150 and g < 100 and b < 100:
							return 'flag_color'
						# Blue numbers (1)
						if b > 140 and b > r + 40 and b > g + 40:
							return 'blue'
						# Green numbers (2)
						if g > 130 and g > r + 30 and g > b + 30:
							return 'green'
						# Red numbers (3)
						if r > 140 and r > g + 40 and r > b + 40:
							return 'red'
						# Covered tiles: mid-gray-ish
						if abs(r - g) < 20 and abs(r - b) < 20 and 70 < r < 170:
							return 'covered_gray'
						# Open empty tiles (light)
						if r > 200 and g > 200 and b > 200:
							return 'empty_light'
						return 'other'


					def scan_board_state(board_rect, rows, cols, debug=False):
						"""Scan board and return a 2D list of tile states.

						States: 'covered', 'flag', 0..8 (numbers), 'unknown'
						"""
						require_pyautogui()

						left, top, width, height = board_rect
						tile_w = width / cols
						tile_h = height / rows

						img = pyautogui.screenshot(region=(left, top, width, height))

						grid = [[None for _ in range(cols)] for _ in range(rows)]

						for r in range(rows):
							for c in range(cols):
								cx = int((c + 0.5) * tile_w)
								cy = int((r + 0.5) * tile_h)

								# sample center and offsets to reduce misclassification
								samples = [img.getpixel((cx, cy))]
								offs = [(-int(tile_w * 0.15), 0), (int(tile_w * 0.15), 0), (0, -int(tile_h * 0.15)), (0, int(tile_h * 0.15))]
								for dx, dy in offs:
									sx = min(max(cx + dx, 0), width - 1)
									sy = min(max(cy + dy, 0), height - 1)
									samples.append(img.getpixel((sx, sy)))

								votes = {'flag_color': 0, 'blue': 0, 'green': 0, 'red': 0, 'covered_gray': 0, 'empty_light': 0, 'other': 0}
								for px in samples:
									cat = _classify_pixel(px)
									votes[cat] = votes.get(cat, 0) + 1

								if debug:
									print(f"tile {r},{c} votes={votes}")

								if votes['flag_color'] >= 1:
									grid[r][c] = 'flag'
								elif votes['blue'] >= 1:
									grid[r][c] = 1
								elif votes['green'] >= 1:
									grid[r][c] = 2
								elif votes['red'] >= 1:
									grid[r][c] = 3
								elif votes['empty_light'] >= 1:
									grid[r][c] = 0
								elif votes['covered_gray'] >= 1:
									grid[r][c] = 'covered'
								else:
									grid[r][c] = 'unknown'

						return grid


					def _neighbors(rows, cols, r, c):
						for dr in (-1, 0, 1):
							for dc in (-1, 0, 1):
								if dr == 0 and dc == 0:
									continue
								nr, nc = r + dr, c + dc
								if 0 <= nr < rows and 0 <= nc < cols:
									yield nr, nc


					def solve_board(board_rect, rows, cols, do_actions=True, dry_run=False, debug=False, max_iters=200):
						"""Run deterministic solver rules until no progress or max_iters reached.

						Returns a summary dict with counts of actions performed.
						"""
						require_pyautogui()
						left, top, width, height = board_rect
						tile_w = width / cols
						tile_h = height / rows

						actions = {'clicked': 0, 'flagged': 0, 'iterations': 0}

						for iteration in range(max_iters):
							actions['iterations'] += 1
							grid = scan_board_state(board_rect, rows, cols, debug=debug)
							"""minesweeper.py

							Small helper module for Minesweeper automation. Provides a simple
							deterministic solver that uses two basic Minesweeper rules and can
							optionally perform clicks via pyautogui. The module is safe to import
							even when pyautogui is not installed; functions that require live
							interaction will raise if pyautogui is missing.
							"""

							try:
								import pyautogui
							except Exception:
								pyautogui = None


							def require_pyautogui():
								if pyautogui is None:
									raise RuntimeError("pyautogui is required. Install it with: python -m pip install pyautogui")
								return pyautogui


							def find_board_and_ui_defaults(screen_width=None, screen_height=None):
								"""Return a heuristic default board rectangle and UI element positions.

								Returns (board_left, board_top, board_width, board_height, flags_center, smiley_center)
								"""
								if screen_width is None or screen_height is None:
									if pyautogui:
										screen_width, screen_height = pyautogui.size()
									else:
										screen_width, screen_height = (2560, 1440)

								board_w = int(screen_width * 0.6)
								board_h = int(screen_height * 0.6)
								board_left = int((screen_width - board_w) / 2)
								board_top = int(screen_height * 0.18)

								flags_center = (board_left + int(board_w * 0.08), int(screen_height * 0.08))
								smiley_center = (board_left + int(board_w / 2), int(screen_height * 0.08))

								return (board_left, board_top, board_w, board_h, flags_center, smiley_center)


							def _classify_pixel(px):
								"""Classify an RGB pixel into a small set of categories.

								Possible returns: 'flag_color', 'blue', 'green', 'red', 'covered_gray', 'empty_light', 'other'
								"""
								r, g, b = px[:3]
								if r > 150 and g < 100 and b < 100:
									return 'flag_color'
								if b > 140 and b > r + 40 and b > g + 40:
									return 'blue'
								if g > 130 and g > r + 30 and g > b + 30:
									return 'green'
								if r > 140 and r > g + 40 and r > b + 40:
									return 'red'
								# darker/brown-ish numbers (5..8) — add loose detection for them
								if r > 100 and g < 120 and b < 120 and r > g and r > b:
									return 'brownish'
								if abs(r - g) < 20 and abs(r - b) < 20 and 70 < r < 170:
									return 'covered_gray'
								if r > 200 and g > 200 and b > 200:
									return 'empty_light'
								return 'other'


							def scan_board_state(board_rect, rows, cols, debug=False):
								"""Scan the board rectangle and return a rows x cols grid of states.

								States: 'covered', 'flag', 0..8 for numbers, 'unknown'
								"""
								require_pyautogui()

								left, top, width, height = board_rect
								tile_w = width / cols
								tile_h = height / rows

								img = pyautogui.screenshot(region=(left, top, width, height))

								grid = [[None for _ in range(cols)] for _ in range(rows)]
								for r in range(rows):
									for c in range(cols):
										cx = int((c + 0.5) * tile_w)
										cy = int((r + 0.5) * tile_h)

										samples = [img.getpixel((cx, cy))]
										offs = [(-int(tile_w * 0.15), 0), (int(tile_w * 0.15), 0), (0, -int(tile_h * 0.15)), (0, int(tile_h * 0.15))]
										for dx, dy in offs:
											sx = min(max(cx + dx, 0), width - 1)
											sy = min(max(cy + dy, 0), height - 1)
											samples.append(img.getpixel((sx, sy)))

										votes = {'flag_color': 0, 'blue': 0, 'green': 0, 'red': 0, 'covered_gray': 0, 'empty_light': 0, 'other': 0, 'brownish': 0}
										for px in samples:
											cat = _classify_pixel(px)
											votes[cat] = votes.get(cat, 0) + 1

										if debug:
											print(f"tile {r},{c} votes={votes}")

										# map color votes to numbers; primary cases first
										if votes['flag_color'] >= 1:
											grid[r][c] = 'flag'
										elif votes['blue'] >= 1:
											grid[r][c] = 1
										elif votes['green'] >= 1:
											grid[r][c] = 2
										elif votes['red'] >= 1:
											grid[r][c] = 3
										elif votes.get('brownish', 0) >= 1:
											# brownish likely corresponds to 5-8 depending on style; return as 5 to indicate higher number
											grid[r][c] = 5
										elif votes['empty_light'] >= 1:
											grid[r][c] = 0
										elif votes['covered_gray'] >= 1:
											grid[r][c] = 'covered'
										else:
											grid[r][c] = 'unknown'

								return grid


							def _neighbors(rows, cols, r, c):
								for dr in (-1, 0, 1):
									for dc in (-1, 0, 1):
										if dr == 0 and dc == 0:
											continue
										nr, nc = r + dr, c + dc
										if 0 <= nr < rows and 0 <= nc < cols:
											yield nr, nc


							def solve_board(board_rect, rows, cols, do_actions=True, dry_run=False, debug=False, max_iters=200):
								"""Run two deterministic Minesweeper rules until no progress.

								Returns a dict: {'clicked': n, 'flagged': m, 'iterations': k}
								"""
								require_pyautogui()
								left, top, width, height = board_rect
								tile_w = width / cols
								tile_h = height / rows

								actions = {'clicked': 0, 'flagged': 0, 'iterations': 0}

								# persistent flags set tracked locally so they are considered in subsequent iterations
								persistent_flags = set()

								for iteration in range(max_iters):
									actions['iterations'] += 1
									grid = scan_board_state(board_rect, rows, cols, debug=debug)
									to_click = []
									to_flag = []

									for r in range(rows):
										for c in range(cols):
											val = grid[r][c]
											# treat flagged cells from either scan or persistent bookkeeping
											if grid[r][c] == 'flag':
												persistent_flags.add((r, c))

											if isinstance(val, int) and val >= 0:
												flagged = 0
												covered = []
												for nr, nc in _neighbors(rows, cols, r, c):
													nbr = grid[nr][nc]
													if nbr == 'flag' or (nr, nc) in persistent_flags:
														flagged += 1
													elif nbr == 'covered' or nbr == 'unknown':
														covered.append((nr, nc))

												# Rule 1: if number == flagged -> covered neighbors are safe
												if val == flagged and covered:
													for (nr, nc) in covered:
														to_click.append((nr, nc))
												# Rule 2: if number == flagged + covered_count -> all covered are mines
												elif val == flagged + len(covered) and covered:
													for (nr, nc) in covered:
														to_flag.append((nr, nc))

									# deduplicate while preserving order
									to_click = list(dict.fromkeys(to_click))
									to_flag = list(dict.fromkeys(to_flag))

									if not to_click and not to_flag:
										if debug:
											print("No deterministic moves found, stopping")
										# fallback: if no deterministic move, pick a pseudo-random covered tile to click
										import random
										covered_cells = [(r, c) for r in range(rows) for c in range(cols) if grid[r][c] == 'covered' and (r, c) not in persistent_flags]
										if covered_cells:
											choice = random.choice(covered_cells)
											# 50/50 style: use random bit to decide to click or flag (simulate guess)
											if random.random() < 0.5:
												to_click = [choice]
												if debug:
													print(f"Random fallback: clicking {choice}")
											else:
												to_flag = [choice]
												persistent_flags.add(choice)
												if debug:
													print(f"Random fallback: flagging {choice}")
										else:
											break

									# perform actions
									for (r, c) in to_click:
										cx = int((c + 0.5) * tile_w)
										cy = int((r + 0.5) * tile_h)
										x = left + cx
										y = top + cy
										if debug:
											print(f"Clicking safe tile at {r},{c} -> {x},{y}")
										if not dry_run and do_actions:
											pyautogui.click(x, y, button='left')
											pyautogui.sleep(0.06)
										actions['clicked'] += 1

									for (r, c) in to_flag:
										cx = int((c + 0.5) * tile_w)
										cy = int((r + 0.5) * tile_h)
										x = left + cx
										y = top + cy
										if debug:
											print(f"Flagging tile at {r},{c} -> {x},{y}")
										if not dry_run and do_actions:
											pyautogui.click(x, y, button='right')
											pyautogui.sleep(0.06)
										actions['flagged'] += 1

									if not dry_run and do_actions:
										pyautogui.sleep(0.2)

								return actions


							def interactive_solve():
								"""Interactive solver entrypoint: prompt for board region and run solver once."""
								if pyautogui is None:
									print("pyautogui missing; install it first")
									return

								sw, sh = pyautogui.size()
								board_left, board_top, board_w, board_h, _, _ = find_board_and_ui_defaults(sw, sh)

								print("Detected screen size:", sw, "x", sh)
								print("Default board rect:", (board_left, board_top, board_w, board_h))
								ans = input("Press Enter to accept defaults, or 'c' to configure: ")
								if ans.strip().lower() == 'c':
									try:
										board_left = int(input(f"board_left [{board_left}]: ") or board_left)
										board_top = int(input(f"board_top [{board_top}]: ") or board_top)
										board_w = int(input(f"board_w [{board_w}]: ") or board_w)
										board_h = int(input(f"board_h [{board_h}]: ") or board_h)
									except ValueError:
										print("Invalid numbers, aborting")
										return

								try:
									rows = int(input("Tile rows [9]: ") or 9)
									cols = int(input("Tile cols [9]: ") or 9)
								except ValueError:
									print("Invalid grid, aborting")
									return

								dry = input("Dry run (no clicks)? (Y/n): ")
								dry_run = (dry.strip().lower() in ('y', 'yes', ''))

								confirm = input("About to run solver. Move mouse away. Type 'run' to continue: ")
								if confirm.strip().lower() != 'run':
									print("Aborted")
									return

								print("Starting in 3 seconds...")
								pyautogui.sleep(3)

								summary = solve_board((board_left, board_top, board_w, board_h), rows, cols, do_actions=not dry_run, dry_run=dry_run, debug=True)
								print("Solver finished:", summary)


							if __name__ == '__main__':
								if pyautogui:
									print('pyautogui available, version:', getattr(pyautogui, '__version__', 'unknown'))
								else:
									print('pyautogui not available. See requirements.txt to install dependencies.')

								try:
									run = input("Run automated deterministic solver now? (y/N): ")
									if run.strip().lower() == 'y':
										interactive_solve()
								except Exception:
									pass

