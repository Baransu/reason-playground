let getOrElse = (default, option) =>
  switch (option) {
  | Some(a) => a
  | None => default
  };